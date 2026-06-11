#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
#include<memory.h> 
#include<sstream>
#include<time.h>
#include<iomanip>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const long long MOD=998244353;
const long long LMOD=154590409516822759;
//const long long LMOD=1000000007;
#define Fi first
#define Se second
#define P2 pair
#define Pii pair<int,int>
#define Pll pair<long long,long long>
#define Cb make_pair
#define ll long long
#define Ull unsigned long long
#define Sf scanf
#define Pf printf
#define Pb push_back
#define Psh push
#define Stc stack
#define Vct vector
#define Ret return
#define Re0 return 0
#define Sz size
#define Is insert
#define Que queue
#define Emp empty
#define Fro front
#define Rv reverse
#define Er erase
#define Bg begin
#define Srt sort
#define Pq priority_queue
#define Ins insert
#define Ite iterator
#define Cou count
#define Cot continue
#define Beg begin
int main()
{
	int n,t,g=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if((i&1)&(t&1))g++;
	}
	cout<<g;
	return 0;
}