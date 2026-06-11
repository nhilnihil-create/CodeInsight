#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<int> s;
    int x,n;
    cin >> x >> n;
    if(n == 0){
        cout << x << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    int idx = 0;
    while(true){
        if(s.find(x-idx) == s.end()){
            cout << x-idx << endl;
            break;
        }
        if(s.find(x+idx) == s.end()){
            cout << x+idx << endl;
            break;
        }
        idx++;
    }
    return 0;

}
