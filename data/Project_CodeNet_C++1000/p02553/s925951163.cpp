#include <iostream>

#define MAX(A, B) ((A>B) ? A : B)
#define NUM 4
using namespace std;


int main(void){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    
    long long ans_candidate[NUM] = {a*c, a*d, b*c, b*d};
    for(int i = 0; i < NUM-1; i++){
        ans_candidate[i+1] = MAX(ans_candidate[i], ans_candidate[i+1]);
    }
    cout << ans_candidate[NUM-1] << endl;
    
    return 0;
}
