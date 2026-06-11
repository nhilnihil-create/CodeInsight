#include<bits/stdc++.h>
#define PB push_back
#define FO(i,a,b) for (int i = a; i <= b; i++)
#define FOb(i,a,b) for(int i=b;i>=a;i--)
#define vi vector<int>
#define vulli vector<unsigned long long int>
using namespace std;
typedef unsigned long long int ulli;
void solve()
{   
    int s,i = 0;
    cin >> s;
    string str;
    cin >> str;
    if(s%2 == 0)
        for(i;i<s/2;i++)
            if(str[i] != str[(s/2)+i])
                break;
    if(i == s/2 && s%2 == 0)
        cout << "Yes";
    else
        cout << "No";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ulli t=1;
   // cin>>t;   
    while(t--){ solve(); cout<<"\n"; }
    return 0;
}
