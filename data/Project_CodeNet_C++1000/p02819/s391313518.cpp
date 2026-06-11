#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

const int Num = 1e5+10;
bool primes [Num+5];
vector <int> p = {2};

void sieve (){

    memset( primes , true , Num );

    primes[0] = primes[1] = false;

    for (int i = 4 ; i <= Num ; i += 2)
        primes[i] = false;

    int sq = sqrt(Num);
    for (int i = 3 ; i <= sq ; i += 2){
        if (primes[i]){
            p.push_back(i);
            for (int j = i*i ; j <= Num ; j += i)
                primes[j] = false;
        }
    }

    for (int i = (sq + (sq&1^1)) ; i < Num ; i += 2)
        if (primes[i])
            p.push_back(i);

}


void Suhaib_Sawalha (){

    sieve();
    int n;
    cin >> n;
    cout << *lower_bound(p.begin(),p.end(),n);

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