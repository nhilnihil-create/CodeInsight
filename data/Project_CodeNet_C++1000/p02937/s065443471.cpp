#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
set<int>  st[125];
int main()
{
  //freopen("input.txt","r",stdin);
   string s,t;
   cin>>s>>t;
   for(int i = 0;i<s.size();++i)
   {
       st[s[i]].insert(i);//储存s中每个字符发生的位置
   }
   int a = 0,b = 0;
   for(int i = 0;i<t.size();++i)
   {
       if(st[t[i]].empty()) return cout<<-1,0;//如果没有出现在s中的字符，肯定无解
       if(st[t[i]].lower_bound(b)==st[t[i]].end()) a++,b = 0;//二分查找>=b的位置是否存在t[i]，
                                                         //若没有则加一个字符串
       b = *st[t[i]].lower_bound(b);//找到该字符出现的下标位置
       b++;
   }
   cout<<a*s.size()+b<<endl;
}