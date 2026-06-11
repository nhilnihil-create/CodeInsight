#include <bits/stdc++.h>
using namespace std;
#define soort(v) sort(v.begin(),v.end())
#define foor(i,n) for(int i=0; i<n; i++)
//#define vecprint(v){for(int i=0; i<v.size(); i++)cout << v[i] << " ";}
int string_to_int(string s){stringstream x(s);double a=0; x>>a; return a;}
long long int gcd(long long int a, long long int b){if(a%b==0)return b;return gcd(b, a%b);}
long long int lcm(long long int a, long long int b){return (a*b)/gcd(a, b);}
//int string_sum(string s){int b = 0;auto k =s.size();for(int j=0; j<k; j++){b +=(s[j]-48);}return b;}
//long long int factorial(long long int n){if (n == 0)return 1;return n * factorial(n - 1);}
 
//int cnt =0;
 
//void SieveOfEratosthenes(int n=20000000)
//{
//   // v.push_back(1);
//
//   bool prime[n+1];
//   memset(prime, true, sizeof(prime));
//
//    vector <bool>prime(n+1,true);
//
//    for (int p=2; p*p<=n; p++)
//    {
//
//        if (prime[p] == true)
//        {
//
//            for (int i=p*p; i<=n; i += p)
//                prime[i] = false;
//        }
//    }
//
//
//    for (int p=2; p<=n; p++)
//       if (prime[p])
//          mp[p]++;
//}
 
 
//set <int>s;
//void primeFactors(long double n)
//{
//
//    while(fmod(n, 2)==0)
//    {
//        s.insert(2);
//        n /= 2;
//    }
//
//
//    for(int i=3; i<=sqrt(n); i+=2)
//    {
//
//        while(fmod(n, i)==0)
//        {
//            s.insert(i);
//            n /= i;
//        }
//
//    }
//
//    if(n>2){
//       s.insert(n);
//    }
//
//}
 

//int isprime(long long int N){
//    if(N<2 || (!(N&1) && N!=2))
//        return 0;
//    for(long long int i=3; i*i<=N; i+=2){
//        if(!(N%i))
//            return 0;
//    }
//    return 1;
//}

//int binary_ser(vector<int>&v,int target,int r,int l=0){
//
//    int mid;
//    mid = l+((r-l)/2);
//
//    if(l>r)return -1;
//
//    if(v[mid]==target)return mid;
//    else if(v[mid]>target){
//        r = mid-1;
//        return binary(v, target,r,l);
//    }
//    else{
//        l = mid+1;
//        return binary(v, target,r,l);
//    }
//
//    return -1;
//
//}

//int lcs(string s,string p){
//
//    vector<vector<int>>v(s.size()+1,vector<int>(p.size()+1));
//
//    for(int i=1; i<=s.size(); i++){
//        for(int j=1; j<=p.size(); j++){
//
//    if(s[i-1]==p[j-1]) v[i][j] = v[i-1][j-1]+1;
//
//    else v[i][j] = max(v[i-1][j], v[i][j-1]);
//
//  }
// }
//
//    return v[s.size()][p.size()];
//}


int main(){
   
    
    int a,b,c,n;
    cin >> a >> b;
    
    if(b==1)cout << 0 << endl;
    else{
        cout << a-b << endl;
    }
    
}
