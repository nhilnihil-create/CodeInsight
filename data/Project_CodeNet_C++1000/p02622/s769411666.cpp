#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >> a;
    cin >> b;
    int count = 0;
    for (int i=0;i<=a.size();i++){
        if (a[i]!=b[i]){
            count++;

        }

    }
    cout << count;
}
