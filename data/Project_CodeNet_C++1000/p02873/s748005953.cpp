#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;

    vector<long> v(s.size()+1, 0);

    //printf("aaa\n");

    for(long i = 0; i < s.size(); i++){
        if(s[i] == '<'){
            v[i+1] = v[i] + 1;
        }
        
    }

    //printf("bbb\n");
    
    for(long long i = s.size()-1; i >= 0; i--){
        if(s[i] == '>'){
           
            v[i] = max(v[i+1] + 1, v[i]);
           
        }
    }

    long long sum = 0;

    for(long long  i = 0; i <= s.size(); i++){
        sum += v[i];
    }

    printf("%lld\n", sum);

    return 0;
    
}