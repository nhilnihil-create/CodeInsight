#include <iostream>
#include <utility>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> point;

const double EPS = 1e-9;
double cross(point a,point b){
    return imag(conj(a)*b);
}

bool is_parallel(point a1,point a2,point b1,point b2){
    return abs(cross(a2-a1,b2-b1)) < EPS;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        vector<point> ps(4);
        for(int j=0;j<4;j++){
            cin >> ps[j].real() >> ps[j].imag();
        }
        if(is_parallel(ps[0],ps[1],ps[2],ps[3])){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}