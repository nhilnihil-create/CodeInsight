#include <set>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define pb push_back

using namespace std;

int main() {
	int n, t, val = 0, s[300000], cnt[300000], temp, ada[300000];
	vector<int> tambah;
	set<int> masih, done;
	set<int>::iterator it, ti;
	scanf("%d", &n);
	t = (1 << n);
	for (int i = 0; i < t; i++)
		scanf("%d", &s[i]);
	sort(s, s + t);
	memset(cnt, 0, sizeof cnt);
	memset(ada, 0, sizeof ada);
	for (int i = 0; i < t; i++) {
		temp = s[i];
		masih.insert(val);
		while (i < t) {
			if (s[i] != temp)
				break;
			s[i++] = val;
			cnt[val]++;
		}
		i--;
		val++;
	}
	cnt[val - 1]--;
	if (cnt[val - 1] < 1)
		masih.erase(val - 1);
	done.insert(val - 1);
	ada[val - 1]++;
	while (n--) {
		tambah.clear();
		for (it = done.begin(); it != done.end(); it++) {
			val = *it;
			for (int i = 0; i < ada[val]; i++) {
				ti = masih.lower_bound(val);
				if (ti == masih.begin()) {
					puts("No");
					return 0;
				}
				ti--;
				temp = *ti;
				cnt[temp]--;
				if (cnt[temp] == 0)
					masih.erase(temp);
				tambah.pb(temp);
			}
		}
		for (int i = 0; i < (int) tambah.size(); i++) {
			temp = tambah[i];
			ada[temp]++;
			if (ada[temp] == 1)
				done.insert(temp);
		}
	}
	puts("Yes");
	return 0;
}