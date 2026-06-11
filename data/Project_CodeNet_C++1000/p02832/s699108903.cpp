#include <iostream>
using namespace std;

#include <vector>

int main(){
    int n,i,num=1;
    cin >> n; i=n;
    vector<int> p;
    while(i--){
        int tmp;cin >> tmp;
        if(tmp == num) {
            p.push_back(tmp);
            num++;
        }
    }
    if(p.size()==0){
        cout << -1 << endl;
    } else {
        cout << n-p.size() << endl;
    }
}