#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<bitset>
#include<iomanip>
#include<cctype>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
const int inf = 1001001000;

void print(vector<vector<int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

//mod計算用のクラス
class ModInt{
public:
    long long int x;
    long long int mod;
	ModInt(){}
    ModInt(long long int _x, long long int _mod = 1000000007){
        this->x = _x % _mod;
        this->mod = _mod;
    }
	ModInt operator+(ModInt other){
		return ModInt(this->x + (other.x % this->mod),this->mod);
	}
	ModInt operator-(ModInt other){
		long long int res = this->x - (other.x % this->mod);
		if (res < 0) return ModInt(res + this->mod, this->mod);
		return ModInt(res);
	}
	ModInt operator*(ModInt other){
		return ModInt(this->x * (other.x % this->mod),this->mod);
	}
	ModInt operator/(ModInt other){
		return ModInt(*this * other.inv());
	}
	ModInt pow(long long int n){
		ModInt res(1, this->mod), a(this->x, this->mod);
		while (n){
			if (n & 1){
				res = res * a;
			}
			n >>= 1;
			a = a * a;
		}
		return res;
	}
	ModInt inv(){
		return ModInt(this->pow(this->mod - 2));
	}
	void disp(){
		cout << this->x << endl;
	}
};
ostream& operator<<(ostream& stream, const ModInt m){
	stream << to_string(m.x);
	return stream;
}


int main(){
	int n;
	cin >> n;
	vector<int> r(n + 1, 0);
	ModInt ans(1);
	r[0] = 3;
	rep(i, n)
	{
		int now; cin >> now;
		if (r[now] == 0){
			cout << 0 << endl;
			return 0;
		}
		ans = ans * ModInt(r[now]);
		r[now]--;
		r[now + 1]++;
	}
	cout << ans << endl;

	return 0;
}