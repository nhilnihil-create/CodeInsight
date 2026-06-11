
/*______________________________________________Bismillahir Rahmanir Rahim____________________________________________


|            |.----------------.  .----------------.  .----------------.  .----------------.  .----------------.|    |
|            | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |    |
|            | |    _______   | || |      __      | || |   ______     | || |     ____     | || |     _____    | |    |
|            | |   /  ___  |  | || |     /  \     | || |  |_   _ \    | || |   .'    `.   | || |    |_   _|   | |    |
|            | |  |  (__ \_|  | || |    / /\ \    | || |    | |_) |   | || |  /  .--.  \  | || |      | |     | |    |
|            | |   '.___`-.   | || |   / ____ \   | || |    |  __'.   | || |  | |    | |  | || |   _  | |     | |    |
|            | |  |`\____) |  | || | _/ /    \ \_ | || |   _| |__) |  | || |  \  `--'  /  | || |  | |_' |     | |    |
|            | |  |_______.'  | || ||____|  |____|| || |  |_______/   | || |   `.____.'   | || |  `.___.'     | |    |
|            | |              | || |              | || |              | || |              | || |              | |    |
|            | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |    |
|            |'----------------'  '----------------'  '----------------'  '----------------'  '----------------'|    |
|                                                                                                                    |
|                                              Student of Cmputer Science & Engineering                              |                                        |
|                                              Comilla University                                                    |                   |
|                                              Email : ahsanulanamsaboj1999@gmail.com                                |                                      |
|                         _____________________Don't judge a book by it's cover___________________                   |                                                    |
|___________________________________________________________________________________________________________________*/

#include<bits/stdc++.h>
#include<string>
#define ll                      long long int
#define akam                    int t;cin>>t;while(t--)
#define MAX                     1000007
#define YES                     cout<<"YES"<<endl
#define NO                      cout<<"NO"<<endl
#define olta(a)                 reverse(a.begin(),a.end())
#define F                       first
#define S                       second
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define veci                    vector<int>
#define vecl                    vector<long long>
#define vp                      vector<pair<ll, ll> >
#define v_min(a)                *min_element(a.begin(),a.end())
#define v_max(a)                *max_element(a.begin(),a.end())
#define v_sum(a)                accumulate(a.begin(),a.end(),0)
#define un(a)                   a.erase(unique(a.begin(),a.end()),a.end())
#define delete(a)               a.erase(a.begin(),a.end())
#define Sort(a)                 sort(a.begin(),a.end())
#define Saboj                   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
using namespace std;

int main()
{

    Saboj;
    ll n,i,j,d=0,a,b,c,k,tm;
    cin>>n;
    ll arr[n],bal[3];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n-2;i++){


        for(j = i+1;j<n-1;j++){


            for(k = j+1;k<n;k++){
                bal[0] = arr[i];
                bal[1] = arr[j];
                bal[2] = arr[k];
                sort(bal,bal+3);

                if((bal[0]+bal[1])>bal[2]){
                    if(bal[0]!=bal[1] && bal[1]!=bal[2] && bal[2]!=bal[0]){
                        d++;
                       // cout<<bal[0]<<" "<<bal[1]<<" "<<bal[2]<<endl;
                    }
                }
            }

        }

    }
    cout<<d<<endl;
        return 0;

}
