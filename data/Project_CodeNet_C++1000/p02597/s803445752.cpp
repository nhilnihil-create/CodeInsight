#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char t;
char c[200005];

int main()
{
int sum_r=0;//Rに変換する操作をする回数
int sum_w=0;//Wに変換する操作をする回数
cin>>n;
for(int i=0;i<n;i++)
{cin>>t;c[i]=t;if(t=='R')sum_w++;}

//白白白白から始めて赤白白白としていく
int ans=sum_w;
for(int i=0;i<n;i++)
{
if(c[i]=='R'){sum_w--;}
if(c[i]=='W'){sum_r++;}
ans=min(ans,max(sum_r,sum_w));
}

cout <<ans;

}