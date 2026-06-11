#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    double a,b;
    scanf("%lf%lf",&a,&b);
    int ans = int(a)/int(b);
    int ans2 = int(a)%int(b);
    double ans3 = a/b;
    printf("%d\n",ans);
    printf("%d\n",ans2);
    printf("%lf\n",ans3);
}