#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

const int N = 1e5;
ll a[3];
int n , k;
string s;
map <char,int> c_to_i = {{'r',0} , {'s',1} , {'p',2}};
map <int,char> i_to_c = {{0,'r'} , {1,'s'} , {2,'p'}};
map <char,char> d = {{'r','p'} , {'s','r'} , {'p','s'}};
char c[N];

void Suhaib_Sawalha (){

    cin >> n >> k;
    for (int i = 0 ; i < 3 ; ++i)
        cin >> a[i];
    cin >> s;

    for (int i = 0 ; i < k ; ++i)
        c[i] = s[i];
    ll ans = 0;
    for (int i = k ; i < n ; ++i){
        if (d[s[i]] == c[i-k]){
            c[i] = s[i];
            if (i+k < n)
                c[i] = d[d[s[i+k]]];
        }
        else {
            c[i] = d[s[i]];
            ans += a[c_to_i[d[s[i]]]];
        }
    }

    ll ans2 = 0;
    for (int i = 0 ; i < k ; ++i){
        c[i] = d[s[i]];
        ans2 += a[c_to_i[d[s[i]]]];
    }
    for (int i = k ; i < n ; ++i){
        if (d[s[i]] == c[i-k]){
            c[i] = s[i];
            if (i+k < n)
                c[i] = d[d[s[i+k]]];
        }
        else {
            c[i] = d[s[i]];
            ans2 += a[c_to_i[d[s[i]]]];
        }
    }

    cout << max (ans,ans2);
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