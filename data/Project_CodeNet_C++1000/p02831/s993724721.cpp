#include <bits/stdc++.h>
#define ll long long
#include <numeric>
using namespace std;
const int sz = 1e6+5;
ll int arr[sz], arr1[sz];
//ll int arr[100][100]= {0};
bool prime[sz]= {0};
vector <ll int> pr,vec1,vec2;
//vector <pair <int,int>> vec;

int main()
{
    ll int a,b,hcf,temp,lcm;
    cin>>a>>b;

    hcf = a;
    temp = b;

    while(hcf!=temp)
    {
        if (hcf>temp)
            hcf -=temp;
        else
            temp-= hcf;

    }

    lcm = (a*b)/hcf;
    cout<<lcm<<endl;


}
