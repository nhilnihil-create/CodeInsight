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
    long double a[n] , ans;
    for (int i = 0 ; i < n ; ++i)
        cin >> a[i];
    sort(a,a+n);
    ans = (a[0]+a[1]) / 2.0;
    for (int i = 2 ; i < n ; ++i)
        ans = (ans + a[i]) / 2.0;
    
    cout << fixed << setprecision(20) << ans;

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