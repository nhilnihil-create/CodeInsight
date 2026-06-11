#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){ 
int n; cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++) cin >> a[i];
bool ans = true;
for(int i = 0; i < n; i++){
   if(a[i]%2==0){
     if(a[i]%3 != 0 && a[i]%5 != 0) ans = false;
       }
}
if(ans) cout << "APPROVED" << endl;
else cout << "DENIED" << endl;
return 0;
}
