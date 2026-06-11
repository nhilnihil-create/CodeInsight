#include<iostream>
#include<string>

using namespace std;

int main(void) {
    int s, w;
    cin >> s >> w;


    cout << (s <= w ? "unsafe" : "safe") << endl;

    return 0;
}
