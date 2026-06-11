#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    long long int k;
    cin >> s;
    cin >> k;
    
    long long int count = 0;
    int index_s = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] != s[index_s]){
            count += (i-index_s)/2;
            index_s = i;
        }
    }
    
    long long int res = 0;
    if(index_s == 0){
        res = s.length() * k / 2;
    }else{
        if(s[0] != s[s.length() - 1]){
            count += (s.length() - index_s)/2;
            res = count * k;
        }else{
            long long int a, b;
            for(a = 0; s[a] == s[0]; a++);
            for(b = 0; s[s.length()-b-1] == s[0]; b++);
            count -= a/2;
            res = count * k;
            res += a/2;
            res += b/2;
            res += (a+b)/2 * (k-1);
        }
    }
    
    cout << res << endl;
    return 0;
}