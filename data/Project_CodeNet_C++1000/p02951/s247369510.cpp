#include<bits/stdc++.h>

using namespace std;

void test()
{
   int a,b,c;
   cin>>a>>b>>c;
   
   int remain=a-b;
   
   if(remain>c)
    cout<<0<<"\n";
   else
    cout<<c-remain;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
