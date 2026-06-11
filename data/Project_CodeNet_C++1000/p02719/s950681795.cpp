#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    long long N,K;
    cin>>N>>K;

    set<long long> s;
    s.clear();

    long long tmp=N%K;
    while(1){
        tmp=abs(tmp-K);
        if(s.find(tmp)!=s.end()){
            break;
        }
        s.insert(tmp);
    }

    cout<<*s.begin()<<endl;
    

    return 0;
}