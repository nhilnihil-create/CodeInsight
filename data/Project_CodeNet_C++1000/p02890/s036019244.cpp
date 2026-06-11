#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    int a;
    vector<int> cnt1(n,0),cnt2(n+1,0),b(n+1),len(n+1,0);
    for (int i = 0;i < n;++i) {
        scanf("%d",&a);
        cnt1[a-1]++;
    }
    for (int i = 0;i < n;++i) cnt2[cnt1[i]]++;
    for (int i = 0;i < n+1;++i) b[i] = cnt2[i]*i;
    for (int i = 0;i < n;++i) {
        cnt2[i+1] += cnt2[i];
        b[i+1] += b[i];
    }
    for (int i = 1;i < n+1;++i) {
        len[i] = (b[i]+(n-cnt2[i])*i)/i;
    }
    int j = n;
    for (int i = 1;i < n+1;++i) {
        while (j > 0 && len[j] < i) j--;
        cout << j << "\n";
    }
}