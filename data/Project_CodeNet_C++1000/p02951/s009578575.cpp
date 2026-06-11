/*
    @uthor: Varun Mishra
    "varun21999" ->  Codechef, Codeforce, Hackerrank, Hackerearth;
*/
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ull     unsigned int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define ppa     pair<pair<int,int>,int>
#define pap     pair<int,pair<int,int>>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)          sort(v.rbegin(),v.rend())
#define R(v)           reverse(v.begin(),v.end())
#define mxpq(T)        priority_queue <T>
#define mnpq(T)        priority_queue<T,vector<T>,greater<T>>
#define T              int tc;cin>>tc;while(tc--)
#define p2d(v)         for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)         for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)         for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define forIloop(i,n)  for(auto i=0;i<n;i++);
#define forDloop(i,n)  for(auto i=n-1;i>=0;i--);
#define qqq 400005


void codeforceContest(){
    int a,b,c; cin>>a>>b>>c;
    int ans = c-(a-b);
    if(ans<0) cout << "0" << endl;
    else cout << ans << endl;
    return;
}



// void hackerEarth(){
//     int x,n; cin>>x>>n;
//     if(n==1){
//         cout << (x%10) << endl;
//     }
//     else if(n == 2 || n == 3){
//         int a = x%10;
//         if(a == 1) cout << "1" << endl;
//         else if(a==2) cout << "4" << endl;
//         else if(a==3) cout << "9" << endl;
//         else if(a==4) cout << "6" << endl;
//         else if(a==5) cout << "5" << endl;
//         else if(a==6) cout << "6" << endl;
//         else if(a==7) cout << "9" << endl;
//         else if(a==8) cout << "4" << endl;
//         else if(a==9) cout << "1" << endl;
//         else if(a==0) cout << "0" << endl;
//     }
//     else if(n == 4){
//         int a = x%10;
//         if(a == 1) cout << "1" << endl;
//         else if(a==2) cout << "6" << endl;
//         else if(a==3) cout << "1" << endl;
//         else if(a==4) cout << "6" << endl;
//         else if(a==5) cout << "5" << endl;
//         else if(a==6) cout << "6" << endl;
//         else if(a==7) cout << "1" << endl;
//         else if(a==8) cout << "6" << endl;
//         else if(a==9) cout << "1" << endl;
//         else if(a==0) cout << "0" << endl;
//     }
//     else{
//         cout << "0" << endl;
//     }
//     return;
// }

// void Lucario(){
//     T{
//         int n; cin>>n;
//         vector<int>e(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>e[i];
//         }
//         sort(e.begin(), e.end(), greater<int>());
//         int flag=0, i=0;
//         while(i<n)
//         {
//             if(e[i] <= (n-i)){
//                 flag++;
//                 i += e[i];
//             }
//             else{
//                 i++;
//             }
//         }
//         cout << flag << endl;
        


//     }
    
// }



int32_t main(){

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    /*#ifndef _DEBUG
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif*/


    // Lucario();
    codeforceContest();
    //hackerEarth();
    //cerr<<"Time Elapsed: "<<clock()/(double)CLOCKS_PER_SEC<<endl;
    return 0;
}

