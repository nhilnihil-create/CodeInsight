#include<iostream>
#include<bits/stdtr1c++.h>
#include<vector>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define zn(a,b,c) for(ll a=b;a<c;a++)
#define nz(a,b,c) for(ll a=b;a>c;a--)
using namespace std;

double nthRoot(int A, int N) 
{ 
    
    double xPre = rand() % 10; 
  
 
    double eps = 1e-3; 

    double delX = INT_MAX; 

    double xK; 
  

    while (delX > eps) 
    { 
    
        xK = ((N - 1.0) * xPre + 
              (double)A/pow(xPre, N-1)) / (double)N; 
        delX = abs(xK - xPre); 
        xPre = xK; 
    } 
  
    return xK; 
} 

void print(ll arr[],ll n){
    zn(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool square(int n){

    for(int i=1;i*i<=n;i++){
        if((n%i==0) && (n/i==i)){
             return true;
    }
    }
    return false;
}
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    zn(i,0,n) cin>>arr[i];
    ll m=arr[0];
    ll ans=0;
    ll z=0;
    zn(i,1,n){
        if(arr[i]>m){
            m=arr[i];
        }
        ans=ans+max(m-arr[i],z);
    }
    cout<<ans<<endl;
}

// int main(){

//     string s;
//     cin>>s;
//     ll t=s.length();
//     ll ans=0;
//     vector<int> v;
//     zn(i,0,t){
//         v.push_back((s[i])-48);
//     }
//     //   for (auto i = v.begin(); i != v.end(); ++i) 
//     //     cout << *i << " "; 
//     zn(i,0,t){
//         ans+=v[i];
//     }
//     if(ans%9==0){
//         cout<<"Yes"<<endl;
//     }
//     else cout<<"No"<<endl;

// }
// int main(){
//     long double n,x,t;
//     cin>>n>>x>>t;
//     ll c=ceil(n/x);
//     ll ans=c*t;
//     cout<<ans<<endl;
// }
// int main(){
//     long double d,t,s;
//     cin>>d>>t>>s;
//     if(d/s<=t){
//         cout<<"Yes"<<endl;
//     }
//     else{
//         cout<<"No"<<endl;
//     }
// }
// int main(){
//     ll n;
//     cin>>n;
    
//     ll n1=2*n;
//     ll arr[n1];
//     zn(i,0,n1) cin>>arr[i];
//     sort(arr,arr+n1);
//     ll ans=0;
//     for(int i=0;i<n1;i=i+2){
//         ans+=arr[i];
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     ll n;
//     cin>>n;
//     ll arr[n];
//     zn(i,0,n) cin>>arr[i];
//     sort(arr,arr+n);
//     // ll c=arr[0];
//     ll cost=0;
//     // cost=cost+(arr[0]-1);
//     ll c=round(nthRoot(arr[n-1],n-1));
//     // cout<<c<<endl;
//     zn(i,0,n){
//         cost+=abs(arr[i]-pow(c,i));
//     }
//     cout<<cost<<endl;



// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         vector<char> v;
//         set<char> s;

//         string str[n];
//         zn(i,0,n){
//              cin>>str[i];
//              ll n1=str[i].length();
//              zn(j,0,n1){
//                  v.push_back(str[i][j]);
//                  s.insert(str[i][j]);
//              }
//         }
//         ll p=0;
//         ll m=s.size();
//         set<char> :: iterator itr;
//         itr=s.begin();
//         zn(i,0,m){
//             // cout<<*itr<<endl;
//            ll c= count(v.begin(),v.end(),*itr);
//            itr++;
//             if(c%n==0){
//                 p++;
//             }
//             else break;
//         }
//     //   for (auto i = v.begin(); i != v.end(); ++i) 
//     //     cout << *i << " "; 
        
//     //     cout<<p<<endl;
//         if(p==m){
//             cout<<"YES"<<endl;
//         }
//         else cout<<"NO"<<endl;




//     }
// }
// int main(){
//     ll n,k;
//     set<ll> s;
    
//     ll j=0;
//     cin>>n>>k;
//     ll a[n]={0};
//     zn(i,0,n){
//         ll x;
//         cin>>x;
//         ll m=s.size();
//         s.insert(x);
//         ll a1=s.size();
//         // cout<<a1<<" "<<m<<endl;
//         if(a1==m+1){
//             a[j++]=i;
//         }
        
//     }
//     // cout<<s.size()<<endl;
//     if(s.size()>=k){
//         cout<<"YES"<<endl;
//         zn(i,0,k) cout<<a[i]+1<<" ";
//         cout<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
// }
// int main(){
//     ll n;
//     cin>>n;
//     ll arr[n];
//     zn(i,0,n) cin>>arr[i];
//     ll a[]={4,8,15,16,23,42};
//     ll arr1[6];
    
//     zn(i,0,6){
//         ll m=count(arr,arr+n,a[i]);
//         arr1[i]=m;

//     }
//     ll ans=0;
//     print(arr1,6);
//     ll q=*min_element(arr1,arr1+6);
//     zn(i,0,6){
//         ans+=arr1[i]-q;
//     }
//     cout<<ans<<endl;




// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll arr[n];
//         ll a[3]={0};
//         zn(i,0,n){
//              cin>>arr[i];
//              a[arr[i]%3]++;
//         }
//         ll m=min(a[1],a[2]);
//         ll mx=max(a[1],a[2]);
//         ll f=(mx-m)/3;
//         cout<<a[0]+m+f<<endl;
        
//     }
//     }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//       ll n;
//       cin>>n;
//       ll o,t,q;
//       o=n;
//       t=n;
//       q=n;
//       ll count=0;
      
//       while(n>1){
//           if(n%2==0){
//               o=n/2;
//           }
//          if(n%3==0){
//               t=2*n/3;
//           }
//           if(n%5==0){
//               q=4*n/5;
//           }
         
//           ll m=min(o,t);
//           ll m1=min(m,q); 
//           if(m1==n){
//               break;
//           }
//           n=m1;
//           count++;
//       }

    
//     if(n==1) {
//         cout<<count<<endl;
//         }
//     else{
//          cout<<"-1"<<endl;
// }
// }
// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         string s1={};
     
//         string s;
      
//         cin>>s;
//           ll l=s.length();
//     for(ll i=0;i<l;i=i+2){
//         s1=s1+s[i];
//     }
//         cout<<s1<<endl;
       
        
//     }
// }
// int main(){
//     ll t;
//     cin>>t;
//     // ll c=n
//     // ;
//     while(t--){
//         ll a,b,n;
//         ll c=0;
//         cin>>a>>b>>n;
//         ll m=max(a,b);
//         ll mi=min(a,n);
//         while(mi<n){
//             mi+=m;
//             m=mi;
//             c++;

//         }
//         cout<<c<<endl;
//     }

//     }

// int main(){
//     string s;
//     string s1;
//     cin>>s>>s1;
//     string s2;
//     cin>>s2;
//     ll l=s.length();
//     ll l1=s1.length();
//     ll c=0;
//     ll l2=s2.length();
//     sort(s.begin(),s.end());
//     sort(s1.begin(),s1.end());
//     sort(s2.begin(),s2.end());
//     ll i,j;
//     ll m=0;
//     for(i=0,j=0;(i<l || j<l1) && m<l2;){
//         if(s2[m]==s[i]){
//             c++;
//             i++;
//             m++;
//         }
//         else if(s2[m]==s1[j]){
//             c++;
//             j++;
//             m++;
//         }
//         else break;
        
//     }
//     if((l+l1==c) && (l2==c)) cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;

// }
// int main(){
//     ll n,p,q;
//     cin>>n;
//     cin>>p;
//     set<ll> s;
//     zn(i,0,p){
//         ll x;
//         cin>>x;
//         s.insert(x);
//     }
//     cin>>q;
//     zn(i,0,q){
//         ll x;
//         cin>>x;
//         s.insert(x);
//     }
//     // cout<<s.size();
//     if(s.size()==n){
//         cout<<"I become the guy."<<endl;
//     }
//     else{
//         cout<<"Oh, my keyboard!"<<endl;
//     }
// }
// int main(){
//    ll k,l,m,n,d;
//    cin>>k>>l>>m>>n>>d;
//    ll s=0;
//    zn(i,1,d+1){
//        if(i%k && i%l && i%m && i%n) s++;
//    }
//    cout<<d-s<<endl;


// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll c=0;
//         ll arr[n];
//         zn(i,0,n) cin>>arr[i];
//         zn(i,0,n-2){
//             if((arr[i]<arr[i+1]) && (arr[i+1]>arr[i+2])){
//                 cout<<"Yes"<<endl;
//                 cout<<i+1<<" "<<i+2<<" "<<i+3<<endl;
//                 break;
//             }
//             else c++;

//         }
//         if(c==n-2) cout<<"No"<<endl;
//     }
// }
// int main(){
//     ll n;
//     cin>>n;
//     string s1="I hate it ";
//     string s2="I love it ";
//     string s3="I hate that ";
//     string s4="I love that ";
//     zn(i,0,n-1){
//         if(i%2==0){
//             cout<<s3;
//         }
//         else cout<<s4;
//     }
//     if(n%2!=0) cout<<s1;
//     else cout<<s2;

// }
// int main(){
//   ll n;
//   cin>>n;
//   for(int i=n+1;i<9999;i++){
//       ll ci=i;
//       ll a=i%10;
//       ll b=(i/10)%10;
//       ll c=(i/100)%10;
//       ll d=(i/1000)%10;
//       if((a!=b) && (a!=c) && (b!=c) && (a!=d) && (b!=d) && (c!=d)){
//           cout<<ci<<endl;
//           return 0;
//       }


//   }
// }
// int main(){
//     ll n;
//     cin>>n;
//     string s;
//     cin>>s;
//     ll c=0;
//     zn(i,0,n-1){
//         if(s[i]==s[i+1]){
//             c++;

//         }
//     }
//     cout<<c<<endl;
// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll x,y,z,x1,y1,z1;
//         ll ans=0;
//         cin>>x>>y>>z>>x1>>y1>>z1;
//         ll m=min(z,y1);
//         if(z==y1){
//             ans=z*2;
//         }
        
//         else{
//             // cout<<m*2<<endl;
//             ans=m*2;
//             // z=z-y;
//         }
//         ll t=(z1-x)-(y-x1);
//         if(t>=0){
//             ans=ans-(z1-x);
//         }
    
//         cout<<ans<<endl;
        
        
//     }
// }

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         string s;
//         // vector<pair<ll,ll>> v;
//         ll x=0;
//         ll y=0;
//         ll start=0;
//         ll end=0;
//         vector<pair<ll,ll>> c;
        
        
//         cin>>s;
//         zn(i,0,n){
//             start=i;
//             if(s[i]=="L"){
//                x--; 
                
//             }
//               if(s[i]=="R"){
//                x++; 
                
//             }
//             if(s[i]=="U"){
//                y++; 
                
//             } 
//             if(s[i]=="D"){
//                y--; 
                
//             }
//         }
//     }
// }

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll m=0;
//         ll s=n;
//         while(n){
//             n=n-9;
//             m++;
//         }

//         cout<<s+(m)<<endl;
//     }
// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         ll arr[n];
//         ll e=0;
//         ll o=0;
//         zn(i,0,n){
//             cin>>arr[i];
//             if(arr[i]%2==0){
//                 e++;
//             }
//             else{
//                 o++;
//             }
//         }
//         if(e==n){
//             cout<<"NO"<<endl;
//         }
//         else if(o==n && n%2!=0){
//             cout<<"YES"<<endl;
//         }
//         else if(o==n && n%2==0){
//             cout<<"NO"<<endl;
//         }
//         else{
//             cout<<"YES"<<endl;
//         }
//     }

// }
// int main(){
//     ll n;
//     cin>>n;
//     ll ans=0;
//     ll j=2;
//     ll i=1;
//     zn(m,0,n){
//         ans=ans+i;
//         i++;
        
//         if(i==j){
//             i=1;
//             j++;
//         }
//         }
    
//     cout<<ans<<endl;
// }
// int main(){
//     ll n;
//     cin>>n;
//     ll j;
//     j=0;
//     ll ans=0;
//     zn(i,0,n){
//         j=i+1;
//         ans=ans+(n-i)*j;
//     }
//     cout<<ans<<endl;
// }

// int main(){
//     fast;
//     ll n;
//     cin>>n;
//     ll c[n];
//     vector<ll> v;
//     zn(i,0,n){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     ll j=0;
//     for(ll i=1;i<n+1;i++){
//         if(count(v.begin(),v.end(),i)){
            
//         }
//         else{
//             c[j]=i;
//             j++;
//         }
//     }
//     j=0;
//     zn(i,0,n){
//         if(v[i]==0){
//             v[i]=c[j];
//             j++;
//         }
//     }
//     // print(arr,n);
//     zn(i,0,n){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }
    // t=1;
    // while(t--){
    //     ll h,m;
    //     cin>>h>>m;
    //     cout<<(24-h)*60-m<<endl;
    // }
    // while(t--){
    //     ll n,k;
    //     cin>>n>>k;
    //     // n=5;
    //     // k=2;
    //     ll ans,c;
    //     ans=k*(n/k);
    //     if((n%k)>(k/2)){
    //         c=k/2;

    //     }
    //     else if((k/2)>=(n%k)){
    //         c=n%k;
    //     }
    //     cout<<ans+c<<endl;
    // }

// }
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll a,b,c,d;
//         cin>>a>>b>>c>>d;
//         set<ll> s;
//         ll arr[4]={a,b,c,d};
//         sort(arr,arr+4);
//         ll q=arr[0]+arr[1];
//         zn(i,2,4){
//             s.insert(arr[i]);
//         }
//         s.insert(q);

//         if(s.size()==1) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;

//         // ll s=(a*b)+(c*d);
//         // if(square(s)) cout<<"Yes"<<endl;
//         // else cout<<"No"<<endl;
//     }
    
// }
// int main(){
//     ll n;
//     cin>>n;
//     ll arr[n];
//     ll x=0;
//     ll y=0;
//     zn(i,0,n) cin>>arr[i];
//     sort(arr,arr+n);
//     for(int i=0;i<n/2;i++){
//         x+=arr[i];
//     }
//     for(int i=n/2;i<n;i++){
//         y+=arr[i];
//     }
//     cout<<(x*x)+(y*y)<<endl;
// }
// int main(){
//     ll t;
//     cin>>t;
//     ll m1=0;
//     while(t--){
//         ll a,b;
//         cin>>a>>b;
//         m1=max(a+b,m1);
//         
//     }
//     cout<<m1<<endl;

// }
// int main(){
//     fast;
//     // ll t;
//     // cin>>t;
//     ll count=0;
//     // while(t--){
//      string s,s1;
//      cin>>s>>s1;
//      ll l=s.length();
//      ll l1=s1.length();
//      ll i,j;
//      for(i=l-1,j=l1-1;i>-1 && j>-1;i--,j--){
//          if(s[i]==s1[j]){
//              count++;
//          }
//          else{
//              break;
//          }
//      }
//      cout<<l+l1-2*count<<endl;


    
// }
// int main(){

//     fast;
//    	ll t;
//    	cin>>t;
//    	while(t--)
//    	{
//    	ll n;
//        cin>>n;
//        ll arr[n];
//        zn(i,0,n){
//            cin>>arr[i];
//        }
//        ll p=0;
//        ll c=0;
//        zn(i,0,n-1){
//            p=p+max(c,arr[i]-arr[i+1]);
//        }
//        cout<<p<<endl;

// }}
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n,k;
//         cin>>n>>k;
//         ll arr[n];
//         ll arr1[n];
//         ll arr2[n];
        
//         for(int i=0;i<n;i++) cin>>arr[i];
//         ll min=*min_element(arr,arr+n);
//         ll d=*max_element(arr,arr+n);

        
//             for(int t=0;t<n;t++){
//                arr1[t]=d-arr[t];
//            }
//            d=*max_element(arr1,arr1+n);
//             for(int t=0;t<n;t++){
//                arr2[t]=d-arr1[t];
//            }
//            if(k%2==0){
//             for(int i=0;i<n;i++) cout<<arr2[i]<<" ";
//            }
//            else{
//                for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
//            }
        
        
//         cout<<endl;
//     }

// }
// int main(){
//     int n;
//     cin>.n;
//     string s;
//     cin>>s;
//     sring f="RGB";
    
// }
// int main(){
//     int n;
//      cin>>n;
//     string s;
//      cin>>s;
//     int a[6]={0};
//     string arr[]={"RGB","BRG","RBG","BGR","GRB","GBR"};
//     for(int i=0;i<n;i++){
//         if(s[i]!=arr[0][i%3]){
//             a[0]++;
//         }
//          if(s[i]!=arr[1][i%3]){
//             a[1]++;
//         }
//          if(s[i]!=arr[2][i%3]){
//             a[2]++;
//         }
//          if(s[i]!=arr[3][i%3]){
//             a[3]++;
//         }
//          if(s[i]!=arr[4][i%3]){
//             a[4]++;
//         }
//          if(s[i]!=arr[5][i%3]){
//             a[5]++;
//         }
//     //      if(s[i]!=arr[0][i%3]){
//     //         a[0]++;
        
//     //     }
//     }
//     // int *q;
//     // q=min_element(a,a+6);
//     // cout<<q;
//     int mi=a[0];
//     int index=0;
//     for(int i=0;i<6;i++){
//         if(a[i]<mi){
//             mi=a[i];
//             index=i;
//         }
//     }
//     cout<<mi<<endl;
//     int j=0;
//     for(int i=0;i<n;i++){
//         cout<<arr[index][j++];
//         if(j>2) j=0;
        
//     }
//     cout<<endl;

// }
// int main(){
  
//         int n;
//         cin>>n;
//         vector<int> v;
//         set<int> s;
//         for(int i=0;i<n;i++){
//             int x;
//             cin>>x;
//             v.push_back(x);

//         }
//         sort(v.begin(),v.end());
//         long x=v[v.size()-1];
//         long y=0;
//         for(int i=0;i<n;i++){
//             if(x % v[i]==0 && s.count(v[i])==0){ 
//                 s.insert(v[i]);
//                 }
//             else {
//                 y=v[i];
//                 }
//         }
//         cout<<x<<" "<<y<<endl;
// }

// int main(){
//     int t;
//     cin>>t;
//    while(t--){
//        int n;cin>>n;
//        set<long> s;
//        for(int i=0;i<n;i++){
//            int x;cin>>x;
//            s.insert(x);
//        }
//        cout<<s.size()<<endl;
//    }
// }
// int main(){
//     int t;
//     cin>>t;r
//     while(t--){
//         int n;
//         cin>>n;
//         int arr[n];
//         for(int i=0;i<n;i++) cin>>arr[i];
//         // if()
//         for(int i=0;i<n;i++){
//             if(arr[i]%2=0) c++;
//             if(arr[i]%2!=0) c1++;
//         }
//         if(!(n%2==0 && c1==n/2 && c==n/2)) cout<<"-1"<<endl;
//        else if(!(n%2!=0 && c1==n/2 && c==n/2+1)) cout<<"-1"<<endl;

        
//     }
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         string b;
//         cin>>b;
//         for(int i=0;i<b.length();i=i+2){
//             cout<<b[i];
//         }
//         cout<<b[b.length()-1];
//         cout<<endl;
//     }
// }
// int main(){
//     string arr;
    
//     cin>>arr;
//     while(1){
//         int c=0;
//         // sort(arr.begin(),arr.end());
//         for(int i=0;i<3;i++){
//             if(arr[i]==arr[i+1]){
//                int t= stoi(arr);
//                 t=t+1;
//                 arr=to_string(t);
//                 break;
//             }
//             else{
//                 c++;
//             }
//         }
//         if(c==3) cout<<arr<<endl; break;
//     }
//     return 0;
// }
// int main(){
//     ll n,k;
//     cin>>n>>k;
//     // vector<char> v;
//     string s;
//     cin>>s;
//     int c=0;
//     char temp='a';
//     for(int i=0;i<26;i++){
//         temp='a'+i;
//         if(k<=0) break;
//         for(int j=0;j<n;j++){
//             if(s[j]==temp){
//                 s[j]='-';
//                 k--;
//             }
//             if(k==0) break;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(s[i]!='-') cout<<s[i]; 
//     }
//     cout<<endl;
//     }
   
// }
// int main(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     for(int i=1;i<n;i++){
//         if(n%i==0){
//             reverse(s.begin(),s.begin()+i);
//         }
//     }
//     reverse(s.begin(),s.end());
//     cout<<s<<endl;
// }
// int main(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     int count=0;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//       cin>>arr[i];
//     }
//     // v={4,2,3,1,5,1,6,4};
//     //  vector<int>::iterator it1,it2;
//     //     it1=v.begin();
//     //     it2=v.end();
//     int i=0;
//     int j=n-1;
//      while((arr[i]<=k || arr[j]<=k) && j>=i){
       
//         if(arr[i]<=k){
        
//             i++;
//             count++;
//         }
//         else if(arr[j]<=k){
           
//             j--;
//             count++;
//         }
//     }
//     cout<<count<<endl;
// }
// int main(){
  
//         int n;
//         cin>>n;
//         int s[n];
//         for(int i=0;i<2*n;i++) cin>>s[i];
//         int n1=n/2;
//         int c;
//         int no=0;
//         int m=0;
//         for(int i=0;i<2*n;i++){
//             c=0;
//             for(int j=i-1;j>-1;j--){
                
//                 if(s[i]==s[j]){
//                 no++;
//             }
//              else{
//                  c++;
//             //    m=no;  
//             //     m=min(no,m);
//             // }

//         }
//         }
//         if(c==i){
//             no--;
//             m=min(no,m);
//         }
//         }
//     cout<<abs(m)<<endl;
//     }

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll a,b,c;
//         cin>>a>>b>>c;
//         ll m=c%a;
//         if(m<b){
//             cout<<c-(m+a-b)<<endl;
//         }
//         else if(m>b){
//             cout<<c-(m-b)<<endl;
//         }
//         else{
//             cout<<c<<endl;
//         }

//     }
// }
// int main(){
  
//     ll t;
//     cin>>t;
    
//     while(t--){
//           ll x;
//         cin>>x;
//         int count=0;    
//         while(x!=1){
//             if(x%6==0){
//                 x=x/6;
//                 count++;
//             }
//             else if(x%3==0){
//                 x=x*2;
//                 count++;
//             }
//             else{
//                 count=-1;
//                 break;
//             }

//     }
//     cout<<count<<endl;
// }}
// int main(){
//     ll n;
//     cin>>n;


//     ll f[n+1]; 
//      ll i; 
//     f[0] = 0; 
//     f[1] = 1; 
  
//     for(i = 2; i <= n; i++) 
//     { 
        
//        f[i] = f[i - 1] + f[i - 2]; 
//     } 
//     print(f,n+1);
// }