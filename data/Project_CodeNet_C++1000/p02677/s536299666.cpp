
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 21 August 2020 11:13:15 AM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
#define ld long double
#define pi 3.1415926536 
using namespace std;


void solve(){
    long double a,b,h,m;
    cin>>a>>b>>h>>m;
    long double convert = pi/180;
    long double ans = 0;

    long double angle1 = h*30.0+m*0.5;
    long double angle2 = m*6.0;
    long double angle = abs(angle1-angle2);   
    angle = min(angle,360-angle);
    //cout<<angle1<<" "<<angle2<<" "<<angle<<endl;
    ans = (ld)a*a +(ld)b*b - (ld)2*a*b*cos((ld)(angle*convert));
    ans = (ld)sqrt((ld)ans);
    cout<<setprecision(9)<<fixed<<ans<<endl;
}

int32_t main(){
    IOS;
    //int t; cin>>t; while(t--)
    {
        solve();
    }
    return 0;
}

