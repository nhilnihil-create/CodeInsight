int main() {
    int a, b;
    __builtin_scanf("%d %d", &a, &b);
    __builtin_printf("%d %d\n", a * b, 2 * (a + b));
}