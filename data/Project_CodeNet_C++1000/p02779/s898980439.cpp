#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> date;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        date[num]++;
        if(date[num]==2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}