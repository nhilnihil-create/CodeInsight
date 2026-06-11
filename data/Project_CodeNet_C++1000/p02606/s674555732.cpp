/**
 * Я слил Atcoder Beginner Contest 172, решив всего две задачи!
 * Я не могу апнуть синего!
 * Я постоянно сливаю раунды, либо не решив тупую задачу, либо набрав штрафа!
 * Я постоянно уступаю всем своим друзьям и знакомым в контестах и нахожу этому оправдания!
 * Я постоянно придумываю сложные неверные решения к простым задачам!
 * -------------------------------------------------------------
 * -Решать сложные задачи
 * -Участвовать в контестах
 * -Делать виртуальные соревнования
 * -------------------------------------------------------------
 * Не уберу это, пока не начну нормально решать задачи, а не заниматься ерундой!!!
**/
  
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef long long  ll;
#define press_F_to_pay_respect ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn for(int i=0;i<n;i++) 
#define fore(i,a,b) for(int i = a; i < (b); i++)
#define pb push_back 
#define pob pop_back()
#define mp make_pair 
#define sc second 
#define f first 
#define ld long double
#define kek cout<<endl; 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(v) ((v).begin()), ((v).end()) 
#define halt {cout<<"NO"; return 0;}
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int N = 200010;
const int INF = 1e8;
const ll LL_INF=1e10;
const long double pi=3.1415926535;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ld,null_type,less<ld>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// Template functions
string bin_rep(ll n)
{
     string s="";
      for(int i=63;i>=0;i--)
   {
           if(n&(1LL<<i)) s+='1';
           else s+='0';
   }
   return s;
}
int first_bit(int n)
{
  for(int i=0;i<=31;i++)
   {
           if(n&(1<<i)) return i;
   }
}

//------------------------------

int main()
{
    #if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
 press_F_to_pay_respect;
 // cout << fixed << setprecision(12) << ans;
 // string al = "abcdefghijklmnopqrstuvwxyz";
 int l,r,d;
 cin>>l>>r>>d;
 int cnt=0;
 for(int i=l;i<=r;i++) if(i%d==0) cnt++;
 cout<<cnt;
 

 
 
  // cout <<"Runtime is:"<<clock() * 1.0 / CLOCKS_PER_SEC <<endl;
   return 0;
   
   
 
}