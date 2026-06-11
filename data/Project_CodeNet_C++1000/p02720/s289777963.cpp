#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int k;
   cin>>k;
   queue<int> q;
   for(int i=1;i<10;i++)
   {
       q.push(i);
   }
//    if(k<=9)
//    {
//        cout<<k<<"\n";
//        return;
//    }
   k--;
   while(k)
   {
       int f=q.front();
       q.pop();
       if(f%10==9)
       {
           q.push(f*10+f%10-1);
           q.push(f*10+f%10);
       }
       else if(f%10==0)
       {
           q.push(f*10+f%10);
           q.push(f*10+f%10+1);
       }
       else
       {
           q.push(f*10+f%10-1);
           q.push(f*10+f%10);
           q.push(f*10+f%10+1);
       }
       k--;
   }
   cout<<q.front()<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}