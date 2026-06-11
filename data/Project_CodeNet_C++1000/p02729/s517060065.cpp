#include<iostream>
int main()

{
    int n,m,ans;
    std:: cin >> n >> m;
    ans=n*(n-1)/2+m*(m-1)/2;
    std::cout << ans << std::endl;
    return 0;
}