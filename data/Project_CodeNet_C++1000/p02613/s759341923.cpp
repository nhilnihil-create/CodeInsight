#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int n;
    int countac=0;
    int countwa=0;
    int counttle=0;
    int countre=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a;
        if (a=="AC"){
            countac++;
        }
        else if (a=="WA"){
            countwa++;
        }
        else if (a=="TLE"){
            counttle++;
        }
        else {
            countre++;
        }

    }
    cout << "AC x "+to_string(countac) << endl;
    cout << "WA x "+to_string(countwa) << endl;
    cout << "TLE x "+to_string(counttle) << endl;
    cout << "RE x "+to_string(countre);
}