#include <iostream>

using namespace std;
long long dog;
char a[]={"zabcdefghijklmnopqrstuvwxy"};
int name[13];
int main() {
    cin>>dog;
    int i;
    for ( i=0; dog > 0; i++){
        if (dog%26 == 0) {
            name[i] = 0;
            dog/=26;
            dog--;
        }
        else {
            name[i] = (dog % 26);
            dog /= 26;
        }
    }
    i--;
    for (;i>=0; i--)
        cout<<a[name[i]];
    return 0;
}
