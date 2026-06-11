#include <iostream>
#include <queue>
#include <set>
#include <functional>
#include <random>

struct rolling_hash {
	long long N;
	std::string S;
	long long base;
	long long P1 = 998244353;
	long long P2 = 1000000007;
	long long P3 = 1000000009;
	std::vector<long long> power1;
	std::vector<long long> power2;
	std::vector<long long> power3;
	std::vector<long long> hash1;
	std::vector<long long> hash2;
	std::vector<long long> hash3;

	rolling_hash(std::string& S) : S(S) {
		N = S.size();
		std::random_device seed;
		std::mt19937 rand(seed());
		base = rand() % (P1 - 2) + 2;
		power1.resize(N + 1, 1);
		power2.resize(N + 1, 1);
		power3.resize(N + 1, 1);
		for (long long i = 0; i < N; i++) {
			power1[i + 1] = power1[i] * base % P1;
			power2[i + 1] = power2[i] * base % P2;
			power3[i + 1] = power3[i] * base % P3;
		}
		hash1.resize(N + 1, 0);
		hash2.resize(N + 1, 0);
		hash3.resize(N + 1, 0);
		for (long long i = 0; i < N; i++) {
			hash1[i + 1] = power1[i] * (long long)S[i] % P1;
			hash2[i + 1] = power2[i] * (long long)S[i] % P2;
			hash3[i + 1] = power3[i] * (long long)S[i] % P3;
		}
		for (long long i = 0; i < N; i++) {
			hash1[i + 1] += hash1[i]; hash1[i + 1] %= P1;
			hash2[i + 1] += hash2[i]; hash2[i + 1] %= P2;
			hash3[i + 1] += hash3[i]; hash3[i + 1] %= P3;
		}
	}

	rolling_hash(std::string& S, long long b) : S(S), base(b) {
		N = S.size();
		power1.resize(N + 1, 1);
		power2.resize(N + 1, 1);
		power3.resize(N + 1, 1);
		for (long long i = 0; i < N; i++) {
			power1[i + 1] = power1[i] * base % P1;
			power2[i + 1] = power2[i] * base % P2;
			power3[i + 1] = power3[i] * base % P3;
		}
		hash1.resize(N + 1, 0);
		hash2.resize(N + 1, 0);
		hash3.resize(N + 1, 0);
		for (long long i = 0; i < N; i++) {
			hash1[i + 1] = power1[i] * (long long)S[i] % P1;
			hash2[i + 1] = power2[i] * (long long)S[i] % P2;
			hash3[i + 1] = power3[i] * (long long)S[i] % P3;
		}
		for (long long i = 0; i < N; i++) {
			hash1[i + 1] += hash1[i]; hash1[i + 1] %= P1;
			hash2[i + 1] += hash2[i]; hash2[i + 1] %= P2;
			hash3[i + 1] += hash3[i]; hash3[i + 1] %= P3;
		}
	}

	std::vector<long long> get_hash(long long l, long long r) {
		long long ret1, ret2, ret3;
		ret1 = hash1[r] - hash1[l];
		if (ret1 < 0) ret1 += P1;
		else ret1 %= P1;
		ret1 *= power1[N - l]; ret1 %= P1;

		ret2 = hash2[r] - hash2[l];
		if (ret2 < 0) ret2 += P2;
		else ret2 %= P2;
		ret2 *= power2[N - l]; ret2 %= P2;

		ret3 = hash3[r] - hash3[l];
		if (ret3 < 0) ret3 += P3;
		else ret3 %= P3;
		ret3 *= power3[N - l]; ret3 %= P3;
		return {ret1, ret2, ret3};
	}
};

int main() {
	int N;
	std::string S;
	std::cin >> N >> S;

	rolling_hash rh(S);

	auto find = [&] (int length) {
		if (length * 2 > N) return false;
		std::set<std::vector<long long>> st;
		st.insert(rh.get_hash(0, length));
		std::queue<std::vector<long long>> q;
		for (int j = 1; j < length; j++) q.push(rh.get_hash(j, j + length));
		for (int j = length; j + length <= N; j++) {
			if (st.find(rh.get_hash(j, j + length)) != st.end()) {
				return true;
			}
			q.push(rh.get_hash(j, j + length));
			st.insert(q.front());
			q.pop();
		}
		return false;
	};

	int ok = 0, ng = N;
	while (ok + 1 < ng) {
		int mid = (ok + ng) / 2;
		if (find(mid)) ok = mid;
		else ng = mid;
	}

	std::cout << ok << std::endl;
}