#include <iostream>
#include <sstream>
using namespace std;
string dunction(int x){
    string ans;
    stringstream bruh;
    bruh << x;
    return bruh.str();
}




int main(){
    int n, count;
    count = 0;
    cin >> n;
    string bruh;
    for (int x = 1; x <= n; x++){
        bruh = dunction(x);
        if (bruh.size() % 2 == 1)
            count++;
    }
    cout << count << endl;
}