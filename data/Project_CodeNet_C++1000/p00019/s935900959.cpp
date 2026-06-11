#include <stdio.h>
#include <iostream>

int main(void)
{
long long a;
int n;

scanf("%d", &n);

a = 1;
for (int i = 1; i <= n; i++){
a *= i;
}

std::cout << a << std::endl;

return (0);
}