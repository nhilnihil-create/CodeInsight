#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, counter = 0, value;
    vector<int> a;
    cin>> n;
    while (n){
        cin>> value;
        a.push_back(value);
        n--;
    }
    for(int i = 0; i < a.size(); i+=2)
        if(a[i]%2 != 0)
            counter++;
    cout<< counter;
    return 0;
}
