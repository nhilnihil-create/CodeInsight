/*
                  ,     \    /      ,
                 / \    )\__/(     / \
                /   \  (_\  /_)   /   \
           ____/_____\__\@  @/___/_____\____
          |             |\../|              |
          |              \VV/               |
          |        ------___-------         |
          |__________Chuta Dragon___________|
           |    /\ /      \\       \ /\    |
           |  /   V        ))       V   \  |
           |/     `       //        '     \|
           `              V                '
        */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)
        cin>>ara[i];
}

#define eb emplace_back

int main()
{


    fastread();


    string s;

    cin>>s;


    if(s[0]!=s[1] && s[1]!=s[2] && s[2]!=s[3])cout<<"Good"<<endl;
    else cout<<"Bad"<<endl;






}
