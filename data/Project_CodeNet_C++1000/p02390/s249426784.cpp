int main() {
    int t;
    __builtin_scanf("%d", &t);

    int h = t / 3600;
    int r = (t % 3600) / 60;
    int m = (t % 3600 ) % 60;
    
    __builtin_printf("%d:%d:%d\n", h, r, m);
}