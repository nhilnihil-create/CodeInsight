#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
string s,t;
map<char,int>mp;
map<int,char>mpinv;
set<char>vec;
int to_number1(){
    int num = 0;
    for(int i=0;i<s.length();){
        if(vec.count(s[i])==1){
            num+=mp[s[i]]*mp[s[i+1]];
            i+=2;
        }
        else{
            num+=mp[s[i]];
            i++;
        }
    }
    return num;
}

int to_number2(){
    int num = 0;
    for(int i=0;i<t.length();){
        if(vec.count(t[i])==1){
            num+=mp[t[i]]*mp[t[i+1]];
            i+=2;
        }
        else{
            num+=mp[t[i]];
            i++;
        }
    }
    return num;
}

string convert(int multiply){
    string z = "";
    int digit = 0;
    while(multiply>0){
        int r = multiply%10;
        if(r>0){
            if(r == 1){
                z.push_back(mpinv[pow(10,digit)]);
            }
            else{
                z.push_back(mpinv[pow(10,digit)]);
                z.push_back(mpinv[r]);
            }
        }
        multiply/=10;
        digit++;
    }
    reverse(z.begin(),z.end());
    return z;
}

int main(void){
    for(int i=2;i<=9;i++){
        char x = i+'0';
        mp[x]=i;
        mpinv[i]=x;
        vec.insert(x);
    }
    mp['i']=1;
    mpinv[1]='i';
    mp['x']=10;
    mpinv[10]='x';
    mp['c']=100;
    mpinv[100]='c';
    mp['m']=1000;
    mpinv[1000]='m';
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        int x = to_number1();
        int y = to_number2();
        string z = convert(x+y);
        cout<<z<<endl;
    }
    return 0;
}
