#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <bitset>
#include <string>
#include <utility>
#include <queue>

using namespace std;
long long int bign = 1000000007;
long long int countans(int n,int ind);
// long long int mpown(long long int m,long long int n);
vector<long long int> pow3(100005);
string s;
int main()
{
    
    cin >> s;
    // cout << s.length() << endl;
    // if(s=="1")cout << 3 << endl;
    // long long int ans=mpown(3,s.length()-1);
    
    int n=s.length();
    pow3.at(0)=1;
    
    for(int i=1;i<n+1;i++){
        pow3.at(i)=(pow3.at(i-1)*3)%bign;
    }
    cout << countans(n,0) << endl;
    return 0;
}
// long long int mpown(long long int m,long long int n){
//     if(n==0)return 1;
//     if(n==1)return m%bign;
//     else{
//         long long int temp=mpown(m,n/2);
//         return (((temp*temp)%bign )*(n&1?m:1))%bign;
//     }
// }
long long int countans(int n,int ind){
    if(n==ind)return 1;
    if(s.at(ind)=='1'){
        return (pow3.at(n-ind-1)+(2*countans(n,ind+1))%bign)%bign;
    }else{
        return countans(n,ind+1);
    }
}