#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    long sum = 0, ans = 0, n = 0;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 ==0){}
        else if( i % 3  == 0){}
        else if(i % 5 == 0){}
        else sum += i;
    }

    cout << sum << endl;
}
