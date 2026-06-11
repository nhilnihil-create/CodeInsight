/*
Come on, come on
Put your hands into the fire
Explain, explain
As I turn, I meet the power

This time, this time
Turning white and senses dying
Pull up, pull up
From one extreme to another

From the summer to the spring
From the mountain to the air
From samaritan to sin
And it's waiting on the air

Come on, come on
Put your hands into the fire
Explain, explain
As I turn, I meet the power

This time, this time
Turning white and senses dying
Pull up, pull up
From one extreme to another

From the summer to the spring
From the mountain to the air
From samaritan to sin
And it's waiting on the air

Now I'm low, I'm looking out, I'm looking in
Way down, the lights are dimmer
Now I'm low, I'm looking out, I'm looking in
Way down, the lights are dimmer

Come on, come on
Put your hands into the fire
Come on, come on
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define fir first
#define sec second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define inf 0x3f3f3f3f
#define LINF  0x3f3f3f3f3f3f3f3fll
#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end() 
 
const ll mod = 999983;
#define mx 1000005
const ll mxi = 105;

int main()
{
    fast_as_levi;
    ll n;
    cin>>n;
    ll ar[n];
    ll sm = 0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sm += ar[i];
    }
    sm/=n;
    ll sm1 = sm;
    ll sm2 = sm;
    sm1++;
    sm2--;
    ll ans = 0,ans1 = 0,ans2 = 0;
    for(int i=0;i<n;i++)
    {
        ans += (ar[i]-sm)*(ar[i]-sm);
        ans1 += (ar[i]-sm1)*(ar[i]-sm1);
        ans2 += (ar[i]-sm2)*(ar[i]-sm2);
    }
    cout<<min(ans,min(ans1,ans2));
    
}