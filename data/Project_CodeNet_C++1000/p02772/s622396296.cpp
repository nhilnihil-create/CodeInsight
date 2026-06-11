#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int n;
    cin >> n;
    bool judge = true;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a%2==0 && (a%3!=0&&a%5!=0)){
            judge = false;
            break;
        }
    }
    if(judge) cout << "APPROVED\n";
    else cout << "DENIED\n";
    return 0;
}