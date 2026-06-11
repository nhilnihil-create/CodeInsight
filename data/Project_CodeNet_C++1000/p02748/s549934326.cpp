#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
ll A, B, C;
cin >> A >> B >> C;
vector<ll> rei(A);
vector<ll> denshi(B);
ll rban[200000];
ll dban[200000];
ll wari[200000];

for(int i = 0; i < A; i++){
cin >> rei[i];
}

for(int i = 0; i < B; i++){
cin >> denshi[i];
}
for(int i = 0; i < C; i++){
cin >> rban[i] >> dban[i] >> wari[i];
rban[i]--;
dban[i]--;
}
ll reimin = *min_element(rei.begin(), rei.end());
ll denshimin = *min_element(denshi.begin(), denshi.end());
ll ans = reimin + denshimin;

for(int i = 0; i < C; i++){
ll kakaku = rei[rban[i]] + denshi[dban[i]] - wari[i];
ans = min(ans, kakaku);
}
cout << ans << endl;
}