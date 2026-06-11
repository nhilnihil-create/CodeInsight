#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

void Suhaib_Sawalha (){

    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for (int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        a[i] += a[i-1];
    }

    int ans = 1e9;
    for (int i = 0 ; i < n ; ++i)
        ans = min (ans, abs(a[n]-a[i] - a[i]));
    cout << ans;

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}