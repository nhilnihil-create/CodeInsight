#include <iostream>

int main() {
    using namespace std;
    long long n, a, b;
    cin >> n  >> a >> b;
    long long sets, imp;
    // cout << "a: " << a << endl;
    sets = n / (a + b);
    // cout << "sets: " << sets << endl;
    imp = n % (a + b);
    // cout << "imp: " << imp << endl;
    // cout << "sets b : " << sets * b << endl;
    // cout << "imp -a :" << imp - a << endl;
    if (imp <= a){
        cout << (sets * a) + imp;
    } else {
        cout << (( sets + 1) * a);
    }
}