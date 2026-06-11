#include <iostream>
using namespace std;

int main(){
    int N,R;
    cin >> N >> R;
    cout << R+((N<10)?100*(10-N):0) << endl;
}
