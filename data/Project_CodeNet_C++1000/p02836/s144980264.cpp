 #include <stdio.h>
 #include <string.h>
 char s[101];
 int main(void) {
 scanf("%s", s);
 int res = 0;
 int n = strlen(s);
 for (int i = 0; i < n; i++) {
 if (s[i] != s[n - 1 - i]) res++;
}
printf("%d\n", res / 2);
 }