#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pow;
using std::vector;
using std::string;

int main(){
    long n,res=0;
    bool nao;
    int i,j,k,l;
    string s;
    cin >> n;
    cin >> s;
    for(i=0;i<1000;i++){
        int cnt = 0;
        for(j=0;j<n;j++){
            if(int(s[j])-48 == i/100 && cnt == 0) cnt++;
            else if(int(s[j])-48 == (i/10)%10 && cnt == 1) cnt++;
            else if(int(s[j])-48 == i % 10 && cnt == 2) cnt++;
            
        }
        if(cnt == 3) res++;
    }
    cout << res << endl;
}
