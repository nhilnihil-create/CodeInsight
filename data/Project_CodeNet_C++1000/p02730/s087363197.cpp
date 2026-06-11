#include<bits/stdc++.h>

using namespace std;

bool check(vector<char>s)
{
    int i=0,j=(int)s.size()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;

        i++;
        j--;
    }

    return true;
}
//akasakalevel
void test()
{
   string s;
   cin>>s;

   vector<char>a,b,c;

   for(auto ch:s)
    a.push_back(ch);

   for(int i=0;i<((int)a.size()-1)/2;i++)
    b.push_back(a[i]);

   for(int i=((int)a.size()+2)/2;i<(int)a.size();i++)
   c.push_back(a[i]);//akasaka

   if(check(a) && check(b) && check(c))
    cout<<"Yes";
   else
    cout<<"No";

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}
