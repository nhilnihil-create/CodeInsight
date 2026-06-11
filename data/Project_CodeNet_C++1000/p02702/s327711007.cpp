#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int>g[100003];
vector<int>v(100003);
queue<int>q;

//original

string s;
int n;
int rem[2020];



int main()
{
    cin>>s;
    n = s.size();
    int pow10 =1;
    int num = 0;
    int total = 0;
    rem[0]=1;

    for(int i=n-1;i>=0;i--)
    {
        int digit = s[i]-'0';
        num += digit*pow10;

        total += rem[num%2019];
        rem[num%2019]++;


        pow10 *= 10;
        pow10 %= 2019;
    }
    cout<<total<<endl;


}





