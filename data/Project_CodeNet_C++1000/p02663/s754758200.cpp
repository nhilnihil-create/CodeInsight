#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define loop(i,k,n) for (ll i = k ; i < n ; ++i)
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl

void Suhaib_Sawalha (){

    int H , H2 , M , M2 , k;
    cin >> H >> M >> H2 >> M2 >> k;
    int cool = (M2 - M) + (H2 - H) * 60;
    cout << max (0,cool-k);
}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<endl)
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}
