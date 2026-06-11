#include <cstdio>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int n;
    double sum, avg, disp, std_dev;
    vector<int> scores;
    
    scanf("%d", &n);
    
    while(n != 0) {
        disp = 0;
        scores.resize(n);
        
        for(int i = 0;i < n;i++) {
            scanf("%d", &scores[i]);
        }
        
        sum = accumulate(scores.begin(), scores.end(), 0);
        avg = sum / n;
        
        for(int i = 0;i < n;i++) {
            disp += pow(scores[i] - avg, 2);
        }
        
        disp /= n;
        std_dev = sqrt(disp);
        
        printf("%lf\n", std_dev);
        
        scores.clear();
        scanf("%d", &n);
    }
    
    return 0;
}
