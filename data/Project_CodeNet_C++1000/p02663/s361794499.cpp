 #include<bits/stdc++.h>
/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;

// #define  part ..
#define listi vector<int > 
#define listll vector<long long >
#define pii pair<int ,int > 
#define pll pair<long long ,long long >
#define heap priority_queue<long long >

#define pb(a) push_back(a)
#define mod 1000000007
#define maxx 200006
#define ll long long 
#define quick  	ios_base::sync_with_stdio(NULL),cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// #define test int t;cin>>t;while(t--)
// end of #define 

// define globals ...









//write function from here ...









int Main(){

int a,b,c,d,e;
cin>>a>>b>>c>>d>>e;
int temp = d-b;
if(temp<0){
	c--;
	temp+=60;

}

temp =  max((c-a),0)*60+temp;

temp = temp-e;
cout<<temp;








return 0;



}
























// main function..
int main(){
	quick;  
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Main();
    
    
}
