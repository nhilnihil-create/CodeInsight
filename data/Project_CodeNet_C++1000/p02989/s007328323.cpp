
// Problem : C - Divide the Problems
// Contest : AtCoder - AtCoder Beginner Contest 132
// URL : https://atcoder.jp/contests/abc132/tasks/abc132_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*when the going gets tough the tough gets going  */
/*we are what we repeatedly do , Excellence then is not an act but a habit  - aristotle */
/*The best way to predict the future is to create it - abraham lincoln*/
/*First think , second believe , third dream and finally dare - walt disney*/
/*It is during our darkest moments that we must focus to see the light */
/*Nothing is impossible the word itself says "i'm fucking possible man just try me again and again till i seem impossible "*/
/*Dont judge each day by the harvest you reap but by the seeds you plant */
/*Do not dwell in the past, do not dream of the future, concentrate the mind on the present moment*/
/*Success is not final failure is not fatal : it is the courage to continue that counts */ 
/*the future belongs to those who believe in the beauty of their dreams */
/*The pessimist complains about the wind , the optimist waits for it to change; the realist adjusts the sails  */
/*Believe you can and you are half way there */
/*Everything has beauty but not everyone sees it */
/*Life is not about finding yourself , life is about creating yourself*/
/*You are the average of the 5 people you spend the most time with .........*/
/*Everything is hard before it is easy see for example now the list of examples is very long hahahahahaha...... ......*/
/*I believe in miracles .......*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<bitset>
#include<set>
#include<climits>
#include<math.h>
#include<stdlib.h>
#define lli long long int 
#define pb push_back
#define mp make_pair
#define pii pair<int , int > 
#define pll pair<lli , lli >
#define wht while (t--)
#define fu( i , a  , n ) for ( int i = (int)a ; i <=(int)n ; i++  )
#define fd( i , n , a ) for (int i = (int)n ; i >=(int)a ;i--)
#define rep(i,n) for ( int i = 0 ; i < (int)n;  i++)
#define fst  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz size()
#define ln length()
#define ps printf(" ") 
#define pn printf("\n")
#define pi(n) printf("%d" , n ) 
#define pl(n) printf("%lld" , n )
#define ii(n) scanf("%d" , &n)
#define il(n) scanf("%lld" , &n )
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ALL(V) V.begin(), V.end()
#define ic(n) cin>>n
#define pr printf
#define inf 99999999
using namespace std ;
 
int main()
{
	fst;
	  int n ;
    cin >> n; 
    int arr[n];
    for(int i = 0 ; i < n ;i++ )
    {
      cin>> arr[i];
    }
    int ans = 0;
  sort(arr , arr + n );
  for (int i = 1 ; i <= 100004; i++ )
  {
    int ind = lower_bound(arr, arr + n , i)- arr;
    // if (i ==5 || i == 6 )
    // {
    	// cout << ind << " ";
    // }
    if ((n - ind) == (ind  ) ) 
      ans++;
  }
  cout << ans;
      
 
} 