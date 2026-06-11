#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    string s;
    cin>>s;
    if(s=="SUN"){
        cout<<7<<endl;
    }else if(s=="MON"){
        cout<<6<<endl;
    }else if(s=="TUE"){
        cout<<5<<endl;
    }else if(s=="WED"){
        cout<<4<<endl;
    }else if(s=="THU"){
        cout<<3<<endl;
    }else if(s=="FRI"){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}