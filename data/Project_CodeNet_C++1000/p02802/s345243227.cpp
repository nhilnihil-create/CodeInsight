#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

void Suhaib_Sawalha (){

    map <int,int> mp;
    map <int,bool> done;

    int n , m , k;
    cin >> n >> m;
    string s;
    int ans = 0 , ac = 0;
    while (m--){
        cin >> k >> s;
        if (done[k])
            continue;
        if (s == "WA")
            mp[k]++;
        else {
            ans += mp[k];
            ++ac;
            done[k] = true;
        }
    }

    cout << ac << ' ' << ans;
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