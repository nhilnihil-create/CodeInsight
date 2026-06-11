#include<bits/stdc++.h>

using namespace std;

void test()
{
   int n;
   cin>>n;

   int res=0;

   for(int i=1;i<=n;i++)
   {
       int r=i;
       vector<char>vec;

       while(r)
       {
           vec.push_back((char)(48+r%10));
           r/=10;
       }

       if(vec.size()%2)
        res++;
   }

   cout<<res<<"\n";

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
