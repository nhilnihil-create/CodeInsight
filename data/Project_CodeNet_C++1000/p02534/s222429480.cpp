#include <atcoder/all>
#include <cstdio>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n;
    scanf("%d", &n);
    if(n==1)printf("ACL");
    if(n==2)printf("ACLACL");
    if(n==3)printf("ACLACLACL");
    if(n==4)printf("ACLACLACLACL");
    if(n==5)printf("ACLACLACLACLACL");
    return 0;
}
